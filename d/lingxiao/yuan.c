// Room: /d/lingxiao/yuan.c Ԩ�� 
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short", "����Ԩ��");
	set("long", @LONG
���˷����£���ͷ�������������ȣ��������������뻹�е���£�
���Ͼ������ˡ���ǰ���������������ˣ����������д�˵�����ǣ�����
����������ǰ�ˣ��Ͽ��ȥ�����ɡ�
LONG);
	set("outdoors", "lingxiao");
	set("exits", ([
		"up"   : __DIR__"shanya",
		"down" : __DIR__"bingti",
	]));
	set("coor/x", -31000);
	set("coor/y", -8940);
	set("coor/z", 135);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


