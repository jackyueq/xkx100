// /d/beihai/yuegu.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "�Ĺ�¥");
	set("long", @LONG
�Ĺ�¥ƽ��Ϊһ�����Σ����ȶ�ʮ��麣�����Χ���������������
ʽ¥�ݡ�������ϣ�÷��� (tie)ʯ�̡�ɽ���ϵ�׺��ɽ��ͥ�󣬸�����
�����£���Ķ���ҡ����ƾ�̬ͤ��ˮ���򡢸�¶�����ҡ�Ҿɽͤ�ȡ�
LONG
	);
	set("item_desc", ([
		"tie" : "����֮����ѩʱ������������֮���������������ߡ���Զ����\n",
	]));
	set("exits", ([
		"southup"   : __DIR__"qingxiao",
		"northeast" : __DIR__"yilan",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -200);
	set("coor/y", 4100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
