// Room: /d/taiwan/jilonggang.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ۣ��Ժ���ң����״�Ƽ������������ۿ���ļ�������ò�缦
�����ʺ��������Լ�����֮��������λ��̨�嶫��������̨�庣Ͽ�ı�
�ڣ�һ�����������̫ƽ���Ը۲�����������֮�����ϡ������滷ɽ��
���б���Ϊ����֮�ڣ��������¿Ǹۣ����ϱߣ�����弸ۣ����ߣ���ţ
��ۣ������ߣ��������̶�ǳ��СϪ��������塣 
LONG );
	set("exits", ([
		"west" : __DIR__"danshui",
	]));
	set("objects", ([
		__DIR__"npc/wokou": 3,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2550);
	set("coor/y", -6970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

