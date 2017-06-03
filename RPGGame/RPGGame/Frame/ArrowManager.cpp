#include "ArrowManager.h"


ArrowManager::ArrowManager(void)
{
}


ArrowManager::~ArrowManager(void)
{
}



bool ArrowManager::Init( 
	const Direction eDiresction, 
	const Position oPosition,
	const vector<Option> &vOptions)
{
	m_eDirection = eDiresction;
	m_oPosition  = oPosition;
	m_vOptions   = vOptions;
	return true;
}

int ArrowManager::GetSelectIndex()
{
	int input;
	unsigned int selected = 0;
	gotoxy( m_oPosition.iX, m_oPosition.iY );
	printf(OptionArrow);
	while( true )
	{
		Sleep(100);
		if( _kbhit( ) )
		{
			input = _getch( );

			if( input == 13 )//�س�
				return selected;
			else if( input == 27 )//ESC
				return -1;

			//�����
			if( input == 224 )
			{
				if( _kbhit() )
				{
					input = _getch();
					gotoxy(m_oPosition.iX, m_oPosition.iY);
					printf(OptionClearArrow);
					if( m_eDirection == data::DIRECTION_HORIZONTAL )
					{
						switch( input )//�ƶ�
						{
						case 75://��
							if( selected>0 )
							{
								--selected;
								m_oPosition.iX -= (m_vOptions[selected].sDescription.length() + OptionArrowGap);
							}
							break;
						case 77://��
							if (selected < m_vOptions.size() - 1)
							{
								m_oPosition.iX += (m_vOptions[selected].sDescription.length() + OptionArrowGap);
								++selected;
							}
							break;
						}
					}
					else if(m_eDirection == data::DIRECTION_VERTICAL )
					{
						switch( input )
						{
						case 72://��
							if (selected > 0)
							{
								--m_oPosition.iY;
								--selected;
							}
							break;
						case 80://��
							if ( selected < m_vOptions.size()-1 )
							{
								++m_oPosition.iY;
								++selected;
							}
							break;
						}

					}
					gotoxy( m_oPosition.iX, m_oPosition.iY );
					printf(OptionArrow);
				}
			}
		}
	}
}

data::Option ArrowManager::GetOptionByIndex( unsigned int iIndex )
{
	if ( iIndex < m_vOptions.size())
		return m_vOptions[iIndex];
	return Option();
}
