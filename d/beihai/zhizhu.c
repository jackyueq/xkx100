// /d/beihai/zhizhu.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����ɫ����Ĵ���Ϊ�����������֮������ǰ��һ����
��¯����¯���������ƣ��ɼ�����ʢ����м���ͤ��ͤ��������
��ʯ�������ס�ʯ�������˵�̾���������Ϊ�ྩ�˾�֮һ��
LONG
	);
	set("exits", ([
		"northdown" : __DIR__"shiqiao",
		"southwest" : __DIR__"yongansi",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -180);
	set("coor/y", 4090);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
