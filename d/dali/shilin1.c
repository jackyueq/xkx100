//Room: /d/dali/shilin1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","������ʯ��");
	set("long",@LONG
�ഫ������¡��ң��ʯ��������꣬��ʵ�ʺ죬�����գ�����
Ѱ֮���������ʳ������䡣���Լһǧ����Ķ��������ʯ�֣�Сʯ�֣�
����ʯ�֣���·��ʯ�������֮һ��ǧ��ȼ磬��С�߰�����Ϊ��
����Զ�۵���һƬ���ܴشأ���ȱ�ٱ仯Ծ�������������ͬ����
����Ĵ���Ȼ�ľ���ϸ����ʹ����ʯ����״��״�ޣ������ˣ����
�������Ф�����滹�١�
LONG);
	set("outdoors", "dalin");
	set("exits",([ /* sizeof() == 1 */
	    "east"    : __DIR__"changhu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -38100);
	set("coor/y", -54000);
	set("coor/z", 30);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/sl1",1);
	}
}