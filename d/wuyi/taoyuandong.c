// Room: /d/wuyi/taoyuandong.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "��Դ��");
	set("long", @LONG
��ϲ�����Ӹ����ģ������������ʽ򡱡�����ͨ�ģ�������ӳ��ɽ
�Ŷ�������Ȼ���ʡ�������������������󽧾�ͷ��С��Դ����ʯ����
��С��������һ��ͨ����շת����ʯ�ţ������Կ̡���Դ�������֡�
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"enter"  : __DIR__"taohuayuan",
		"south"  : __DIR__"path7",
		"north"  : __DIR__"path8",
		"eastup" : __DIR__"tianyoupath2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1370);
	set("coor/y", -4970);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

