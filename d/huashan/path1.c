// path1.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "��ɽ����");
	set("long", @LONG
������ɽ��ΡȻ����������ʡ�����س��ϡ�����ƺӣ��������룬
����ɽ��ߵʹ��䣬����һ�����������һ������������ɽ����������
���жȣ�������ɣ�ԶԶ��ȥ��״���޶���������Χ��������꣬�м�
������������ɽ���򡰻���������ȡ����ɽ�������������ٻ�ɽ��
�ʻ�ɽ�ֳ�̫���������С�������µ�һɽ��֮�ƣ�������С�塣����
��ȪԺ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"west"      : "/d/village/eexit",
		"north"     : __DIR__"yuquan",
		"south"     : __DIR__"caishi",
		"southeast" : __DIR__"shaluo",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("coor/x", -920);
	set("coor/y", 270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
 
