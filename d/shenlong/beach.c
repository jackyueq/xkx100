// /d/shenlong/beach.c
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������ĳ����ڣ��˻��Ĵ��Ž�ʯ����������������������һ
ȺȺ��Ÿ��ŷŷ..���ؽ��ţ���ʱ�����Ծ�����棬��������˻���
�������Ҵ�(chuan)�� �������ż�����������ˣ��˴��ɶɹ���
���ﺣ����һ�ˡ��������������ĺ�̲��
LONG
	);
	set("outdoors", "shenlong");

	set("exits", ([
		"east" : __DIR__"haitan",
	]));
	set("item_desc", ([
		"chuan" : "����������������ϵ�Ĵ󴬡����ϵĿ��˻����ֻҪ\n�ϴ�(enter)�Ϳ��Ի���ԭ��\n",
	]));
	set("exits",([
		"east" :__DIR__"haitan",
	]));
	set("outdoors", "shenlong");
	set("coor/x", 4000);
	set("coor/y", 3000);
	set("coor/z", 0);
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
	ob = this_player () ;
	message_vision("����һ�������ϴ���æ����һ��������ඣ�\n", ob);
	message_vision("�������𷫣��������������С�\n", ob);
	ob ->move(__DIR__"dahai") ;
	tell_object(ob, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
	call_out("home", 10 , ob );
	return 1 ;
}
void home( object ob )
{
	tell_object(ob , "�����ڵִ�����ԭ��һ���������С������´�����\n" ) ;
	ob->move ("/d/beijing/haigang") ;
}
