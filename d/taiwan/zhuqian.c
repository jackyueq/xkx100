// Room: /d/taiwan/zhuqian.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "��ǵ");
	set("long", @LONG
��ǵ����̨�嵺���������ǽ��ڱ������в��Ĺ��ɵش���ȫ����ɽ
����̨�أ��غ��ͺ����ذ�ʼ����Сƽԭ�������ϡ���Ϊ���껷������
��̨�庣Ͽ����༾�磬�С���ǡ�֮�ơ��������˿��ѵĺ����ǿͼ�
�ˣ���������ƶ��Ҷ�����ɽ�أ������Ǵ�����ֲ衢ֲ�����Թ�Ϊ����
�˵صļ�˿�����衢���϶�������ǫ̈̄���ز���
LONG );
	set("exits", ([
		"northeast" : __DIR__"danshui",
		"southwest" : __DIR__"maolishe",
	]));
	set("objects", ([
		__DIR__"npc/kejiaren": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2530);
	set("coor/y", -6980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

