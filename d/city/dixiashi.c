// Room: /yangzhou/dixiashi.c
// Last Modified by Winder on Jul. 20 2000

#include <ansi.h>
inherit ROOM;
void create()
{
	set( "short", "������" );
	set( "long" , "����ں����ģ�ʲôҲ��������\n" );
	set( "exits", ([
		"up" : __DIR__"shufengguan",
	]));
	set("coor/x", -11);
	set("coor/y", -47);
	set("coor/z", -10);
	set("no_quest",1);
	setup();
}

void init()
{
	add_action( "do_use", "use" );
}

int do_use( string arg )
{
	object ob, me = this_player();

	if ( !me->can_act() ) return 0;
	if ( arg != "fire" ) return 0;
	if ( objectp ( ob = present( arg, me) ) )
	{
		write( "��ȡ������Ļ�����һ�Σ�" );
		message_vision( "��ʱ�����ǰһ����", me );
		set( "long", @LONG
������Ϊ��խ��ȴ�ܸ���м����һ�����ӣ��������һ��Сϻ�ӡ��������������
ôһ�㶫����
LONG
		);
/*
		��Ӧ�û����ӵ�һ��ʱ�����ģ�
		��������Ƚ��鷳�����ǵ����̫�࣬�Ժ���˵��
		remove_call_out( "no_fire" );
		call_out( "no_fire", 10, ob )
*/
		ob = new( __DIR__"obj/xiaoxiazi" );
		ob->move();
		return 1;
	}
	return 0;
}