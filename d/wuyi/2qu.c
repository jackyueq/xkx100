// Room: /d/wuyi/2qu.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����Ϫ������Ⱥɽ֮�У���Ϫ��ʮ���壬��ˮ��ɽ������������
���ƺ���ɽ��ˮ�㣬�ųơ�����ˮ�������塱������Ϫ�����߾���ͤͤ
��������Ů���ˡ������Ǻں����������֡�ˮ�����ˣ���Ӱ��ͤͤ��Ů��
�Եø������Ķ��ˡ����䡶�������衷Ի������������ͤͤ��Ů�壬��
����ˮΪ˭�ݣ����˲�����̨�Σ�����ǰɽ�伸�ء�������
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"yunvfeng",
		"east"      : __DIR__"1qu",
		"northwest" : __DIR__"3qu",
		"northeast" : __DIR__"tiebanzhan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1390);
	set("coor/y", -5010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

