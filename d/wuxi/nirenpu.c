// Room: /d/wuxi/nirenpu.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
    ����ר�������ز�������ɽ���ˣ���̨�ϰ��˺ü�����̬���쾫
�ɴ�������ˣ���������С������Ϊ����ϲ�������ϰ�ѧ��һ���洫
���������գ�����������Զ��������
LONG );
	set("exits", ([
		"east"  : __DIR__"northroad1",
	]));
	set("objects", ([
			__DIR__"npc/zhang" : 1,
	]));
	set("coor/x", 360);
	set("coor/y", -790);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}