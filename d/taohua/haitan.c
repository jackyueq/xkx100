// Room: /d/taohua/haitan.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>;
inherit ROOM;
void rtaohua( object ob ) ;

void create()
{
	set("short", "��̲");
	set("long", @LONG
�����һ����ĺ�̲�������ĺ��������죬���ɫ��ɳ̲���ۺ����
������һ�ж�����ô�������߲���һ�Ҵ�(chuan)��
LONG );
	set("item_desc", ([
		"chuan" : "�����һ���������ϵ�Ĵ󴬡����ϵĿ��˻����ֻҪ\n�ϴ�(enter)�Ϳ��Ի���ԭ��\n",
	]));
	set("exits",([
		"west" :__DIR__"zoulang5",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taohua");
	set("coor/x", 10000);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
	object ob = this_player () ;
	string dir;
	if( !arg || arg !="chuan" ) 
	{
		tell_object(this_player() , "��Ҫ enter �Ķ���\n" ) ;
		return 1 ;
	}
	message_vision("����һ�������ϴ���æ����һ��������ඣ�\n", ob);
	message_vision("�������𷫣��������������С�\n", ob);
	ob ->move("/d/taohua/dahai") ;
	tell_object(ob, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
	call_out("rtaohua", 10 , ob );
	return 1 ;
}
void rtaohua( object ob )
{
	tell_object(ob , "�����ڵִ�����ԭ��һ���������С������´�����\n" ) ;
	ob->move ("/d/jiaxing/jiaxinggang") ;
}