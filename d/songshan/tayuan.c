// Room: /d/songshan/tayuan.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�����±�ɽ���ϣ��Ƿ�������Ժ��Ժ����ʮ������ܷ������߽���
ʮ�ɣ�����������Ժ��������������Ĺ����������������
LONG );
	set("exits", ([
		"southdown" : __DIR__"fawangsi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "songshan");
	set("coor/x", -30);
	set("coor/y", 820);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}
