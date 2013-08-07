// Room: /binghuo/wangpangang.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����ɽ���");
	set("long", @LONG
����������̵�ɽ����ˡ�������һ���޼ʵĴ󺣣���������һ
Ƭ���֡����ϵĿ����ƺ��������ƣ���ʪ�ĺ����д���һ���ȳ�����
�߲��ż��Ҵ�(chuan)��
LONG );
	set("outdoors", "wangpan");
	set("no_clean_up", 0);
	set("item_desc", ([
		"chuan" : "����Զ��󺣴����ϴ�(enter)�Ϳ��Գ�����\n",
	]));
	set("exits", ([
		"northwest" : __DIR__"wangpanlin",
	]));
	setup();
}

void init()
{
	add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
	object ob ;
	string dir;
	if( !arg || arg !="chuan" ) 
	{
		tell_object(this_player() , "��Ҫ enter �Ķ���\n" ) ;
		return 1 ;
	}
	ob = this_player ();
	if (random(4) >0)
	{
		message_vision("�緫���𣬴�ͷ����ת����������ת�����������������С�\n", ob);
		ob ->move(__DIR__"westboat") ;
		tell_object(ob, BLU "����Ǯ������˳��˳ˮ���磬��������.......\n" NOR ) ;
		call_out("home", 10 , ob );
	}
	else
	{
		message_vision("�緫���𣬴�ͷ����ת�����������������򶫷�������С�\n", ob);
		ob ->move(__DIR__"eastboat1") ;
		tell_object(ob, BLU "���ں���ƾ��ϷŸ�������������......\n" NOR ) ;
		call_out("fore1", 10 , ob );
	}
	return 1 ;
}
void home( object ob )
{
	tell_object(ob , "���ܿ�ͻص������ˡ������´�����\n" ) ;
	ob->move (__DIR__"qiantang") ;
}
void fore1( object ob )
{
	tell_object(ob , "����һ���޼ʵĴ󺣡��㲻���е������㷡�\n" ) ;
	ob->move (__DIR__"eastboat2") ;
	tell_object(ob, BLU "�⴬ȥ�����أ��㲻���е����......\n" NOR ) ;
	call_out("fore2", 10 , ob );
}
void fore2( object ob )
{
	tell_object(ob , "���ܿ�Ϳ��ϵ��ˡ������´�����\n" ) ;
	ob->move (__DIR__"lingshedao") ;
}
