//room: /d/mingjiao/eastdian.c
inherit ROOM;

void init();

void create()
{
	set("short","���̶����");
	set("long", @LONG
�����Ƕ����ǽӴ������ĵط������ڰ��ż������ӣ�����Χ��
�������ӡ�ǽ�����ż����ֻ���ǽ��һ����ܣ����ϰ����鼮��������
ãã����ѩɽ��ѩ�����ࡣ
LONG);
	set("exits",([
		"west" : __DIR__"qiandian",
	]));
	set("no_clean_up", 0);
	set("coor/x", -52020);
	set("coor/y", 1060);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
}