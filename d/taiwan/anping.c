// Room: /d/taiwan/anping.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "��ƽ��");
	set("long", @LONG
����ĩ�꣬�����˳��й���������½̨���ϲ������ڰ�ƽ��������
���ڳǡ��Ӵ˺������������̨�����й����У������˴���Ϊ���ձ�ó
�׵���;վ���������̴˺������������ڳ������Խ��½��У��Ǳ���
���ġ�̨��֡���̨���������ҵ�֡�����ʮ���꣬����ү����������
�ո��˳ǣ���������ƽ�򡹡�
LONG );
	set("exits", ([
		"west"      : __DIR__"luermen",
		"southeast" : __DIR__"zhenbeifang",
	]));
	set("objects", ([
		__DIR__"npc/shangren": 2,
		__DIR__"npc/yufu": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2500);
	set("coor/y", -7030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

