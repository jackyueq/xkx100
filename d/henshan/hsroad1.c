// Room: /d/henshan/hsroad1.c ����·
// Modified By Java Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
������һ����������Ļ���·�ϣ���������ɭɭ�����֡�������ͨ��
���ݣ����Ͼͽ�����ϵؽ��ˡ�
LONG );
	set("outdoors", "hengyang");

	set("exits", ([
		"northdown" : "/d/wudang/wdroad4",
		"southeast" : __DIR__"hsroad2",
	]));

	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", -1000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
