// /d/xiakedao/obj/tongpai1.c
//edit by noz
// Modified by Zeratul Jan 11 2001 ͭ���˳�ʱ���������ܸ���

#include <ansi.h>
inherit ITEM;

void create()
{
  	set_name( "����ͭ��",({"e pai"}));
  	set_weight(100);

  	if( clonep() )
        	set_default_object(__FILE__);

  	set("unit", "��");
  	set("long", "����һ����������İ�ͭƬ�ӣ�Լ�а��ƴ�С�������������һ��������ɷ��������ʮ�ֹ��졣\n" );
	set("no_put",1);
	set("no_get",1);
	set("no_drop",1);
	set("no_beg",1);
	set("no_steal",1);

  	setup();
}

string query_autoload() 
{ 
	if ( query("own") != this_player()->query("id") )
		return 0;
	if ( time() > this_player()->query( "xkd/time" ) )
		return 0;
	return query("own"); 
}

void autoload(string param)
{
	string owner;

	if ( !objectp( this_object() ) )
		return;
	if ( time() > this_player()->query( "xkd/time" ) )
	{
		destruct( this_object() );
		return;
	}
	if( sscanf(param, "%s", owner)==1 )
		set( "own", owner );
}

int init()
{
	string long_msg = this_object()->query( "long" );
	
  	if ( this_player()->query( "xkd/time" ) )
  		long_msg += HIC"���ӱ���̵����֣����͵���" + CHINESE_D->chinese_date( ( (this_player()->query( "xkd/time" ) - 950000000 ) * 60 ) ) + "ǰ�����ݡ�\n"NOR;
  	this_object()->set( "long", long_msg );
	return 1;
}
