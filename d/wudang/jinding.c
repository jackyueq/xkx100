//Room: jinding.c ��
//Date: Sep 22 1997

inherit ROOM;

void create()
{
	set("short","��");
	set("long",@LONG
��е���������Ϯ����ԭ�����ѵ����䵱ɽ������������ľ�����
ǰ��Ľ����ͭ���ɣ����Իƽ�ÿ�������ٿգ�����������������
�����𶥡�������߸߶�����Ⱥ��֮�ϣ�����������ɽ����������壬
�б���һɽ����¯������¯�壬��ɽǧ�֣������·���
LONG);
	set("exits",([ /* sizeof() == 1 */
		"west"      : __DIR__"shierliantai",
		"south"     : __DIR__"zijincheng",
		"northdown" : __DIR__"santiangate",
	]));
	set("objects",([ /* sizeof() == 1 */
	    CLASS_D("wudang")+"/chongxu" : 1,
	]));
	set("outdoors", "wudang");
	set("no_clean_up", 0);
	set("coor/x", -2030);
	set("coor/y", -1040);
	set("coor/z", 180);
	setup();
	replace_program(ROOM);
}
