// Room: /d/gaochang/shulin13.c
// Last Modified by Winder on Jul. 15 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�߲����");
	set("long", @LONG
�������м��߰׹����á�ֻ����빬����Ȼ���ݣ������ж����˻�
ɳ���������ƺ�����·����������վ��һ�����õ�ס��ȥ·��
LONG   
	);

	set("outdoors", "gaochang");
	set("exits", ([
		"south" : __DIR__"zoulangc",
		"north" : __DIR__"mishi2"
	]));
	set("no_clean_up", 0);
	set("coor/x", -36510);
	set("coor/y", 10100);
	set("coor/z", 30);
	setup();
}

void init()
{
	object ob, room;
	ob = this_player();
	room = this_object();

	if (ob->query("id") == "ghost" || !living(ob)) return;
	else if( present("map", ob))
		{
message_vision(HIW"\nͻȻ֮�䣬ǰ��һ����ɭɭ������˵����
����Ȼ���е�֮ʿ!��ô���и߲��Թ��ĵ�ͼ,�ѵ������⣿
�߲��Թ�����ей��ĲƸ��𣿹��������������� 
Ц����͸�����޵������ͱ�״��\n\n" NOR, ob);
		}
		else
		{
message_vision(HIW"\nͻȻ֮�䣬ǰ��һ����ɭɭ������˵����
�ô��߲��Թ�����! ֻ��һ�������Ϯ���������Ҳ�㲻����.
ԭ����һ���������������塣\n\n" NOR, ob);
			ob->die();
		}
}