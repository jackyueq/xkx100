// Room: /d/wuyi/liuxiangjian.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "���㽧");
	set("long", @LONG
��ˮ���������������������⾳���š�������������ұ�´
�����㽧������Ů��ԡʱ�������֬�����ǽ��߻���Ⱦ�������㣿�߽�
���㽧������������ȣ��±����������ٴ�����Ұ��������һ·��ȥ��
��ˮ������ɻ����治�ᣬ�������㣬����Ʈ����
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"south"     : __DIR__"path10",
		"northeast" : __DIR__"path12",
		"southeast" : __DIR__"path11",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1380);
	set("coor/y", -4930);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

