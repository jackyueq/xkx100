// Room: /d/taiwan/pingye.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "ƽҰ");
	set("long", @LONG
��˼���ڱ��۵�½���ڱ��۶��ϰ���ƽҰ��˼��滮�����˾���
��Ӫկ���м�Ϊ���̨��ʹ֮��Ϊ��ָ֯�ӿѻĵ����ࡣ���ͬʱ����
�������ʴ��Ӹ��ġ�Ȫ������ļ����ǰ�����ǧ���ڡ���˼�뽫����
�ֳ�ʮկ�����������͸�ţ��ũ�ߵȣ���ʼ��̨������Ĵ��ģ�ؿѻ�
����
LONG );
	set("exits", ([
		"northwest" : __DIR__"taiwanfu",
		"southeast" : __DIR__"zhuluo",
	]));
	set("objects", ([
		__DIR__"npc/nongfu": 3,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2510);
	set("coor/y", -7020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

