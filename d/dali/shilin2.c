//Room: /d/dali/shilin2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��Ħ��ʯ��");
	set("long",@LONG
����ʯ�ŷ��ʯ���ͣ�ʯ����ڹ��ӣ����ư��磬�����ŭ��
������𣬾���ϸ�µĶ������٣����������侳��̤ʯ�㣬��ʯ�ţ�
��Ұ�ݣ�̽���֣�����ɽ�����ڣ�Σʯɭɭ�����ԭҰ������ɽ����
�󣬻������ƣ�һ��ǿ�ҵ�ɽҰζӭ��������������εĴ������Ȼ
�������˶�Ŀһ�¡�
LONG);
	set("outdoors", "dalin");
	set("objects",([
	    "/d/wudang/npc/tufei1": 2,
	    "/d/wudang/npc/tufei2": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "southwest"    : __DIR__"changhu",
	]));
	set("coor/x", -37900);
	set("coor/y", -53900);
	set("coor/z", 30);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/sl2",1);
	}
}