//Room: /d/dali/jisidawu1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�������");
	set("long",@LONG
�����������ļ�����ݣ���Ϊ������������һ����̨��̨�ϰ�
����һ��������λ����������������֮������λ���ǽ�Ϲ��д����
Ƥ���ϻ����λ��ƣ����Ǹ����ͼ�ڡ�һλ�ϼ�˾�������ڼ�̨ǰ��
����ȫ��ļ�˾���
LONG);
	set("objects", ([
	   __DIR__"npc/laojisi": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "out"      : __DIR__"wuyiminju3",
	]));
	set("coor/x", -90020);
	set("coor/y", -69990);
	set("coor/z", 10);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/jsdw",1);
	}
}