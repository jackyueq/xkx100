// Room: /d/wuyi/9qu.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������з������ʣ�������ȥ������һ��ƽ���ˡ�Ϫ���ڴ�
����������ȫ����ʮ��ľ���Ϫ�ɴ˶�ȥ����Խ�Է壬ֱ�ֳ���Ϫ��
���䡶�������衷Ի�����������������ۻ�Ȼ��ɣ����¶��ƽ������
�ɸ�����Դ·�������˼�����졣��
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northeast" : __DIR__"8qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1320);
	set("coor/y", -5030);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

