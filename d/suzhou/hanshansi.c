// Room: /d/suzhou/hanshansi.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "��ɽ��");
	set("long", @LONG
���߳�����Լ��ʮ��أ��͵��˷���������Ԫ����䣬�и�ɮ��
ɽ�������˾�ס����ϣǨ��ʦ�ڴ˽���Ժʱ��������ɽ�¡��ƿ�Ԫ��䣬
ʫ���ż̸���Ӧ����ڣ���;�۴�ͣ�����ţ���ʫһ�ף�����������˪
���죬�������Գ��ߣ����ճ��⺮ɽ�£�ҹ��������ʹ������Ӵˣ�
ʫ�������������˿ڣ�����ʫ���������¡�
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : __DIR__"road4",
		"enter"     : __DIR__"zhengdian",
	]));
	set("coor/x", 780);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
