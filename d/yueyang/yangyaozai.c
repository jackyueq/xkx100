// Room: /d/yueyang/yangyaozai.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "��ôկ");
	set("long", @LONG
��ôկ����ɽ���ഫ�����γ��궴ͥ��ũ�������������ô��Ӫ��
��ַ��ɽկ�������ɣ�կդ���ڣ������������Ӣ�������������绢��
���ƺ;��춯�ص�ҵ����
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"east" : __DIR__"jiuxiangshan",
	]));
	set("coor/x", -1790);
	set("coor/y", 2290);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
