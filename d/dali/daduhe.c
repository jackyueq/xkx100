//Room: /d/dali/daduhe.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ɺӱ�");
	set("long",@LONG
��ɺ��������������ӹ���խ��ˮ���ļ������Ѷɹ���ֻ��Զ��
���β��к�������������д��ɺӡ��˴��Ǻӹ�ת���ǳ̲��ˮ����
���������Կɼ����Ϻ�ˮ��ӿ��ȥ���԰����������ɼ����ϱ�ɽ����
��ʯ�ǡ�
LONG);
	set("outdoors", "dalin");
	set("exits",([ /* sizeof() == 1 */
	    "southup"  : __DIR__"wunong",
	]));
	set("no_clean_up", 0);
	set("coor/x", -44000);
	set("coor/y", -51000);
	set("coor/z", 10);
	setup();
}
void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/ddh",1);
	}
}