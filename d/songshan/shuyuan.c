// Room: /d/songshan/shuyuan.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "������Ժ");
	set("long", @LONG
����ԭ�������¡������Ļ������ˣ��͸ĳ���������Ժ���������
Ժ����´��Ժ����¹��Ժ�ϳ����¡��Ĵ���Ժ�������γ��������ڴ�
��ѧ��Ժ���йŰ����꣬�����Ѳ�����ˣ����Ϊ�󽫾�������������
������
LONG );
	set("exits", ([
		"southdown" : __DIR__"shandao2",
		"northwest" : __DIR__"shandao3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", 770);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
