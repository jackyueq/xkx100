// Room: /d/luoyang/dianpu.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "����");
	set("long",  @LONG
������һ��ר�����������ʵĵ��̡���˵�����������ʷǳ�������
�õ�����ȥ����������Ӧ�󡣾����˶����ս�ң������ƺ�ֻע������
�����ٹ��ĵ�ǰ������Σ���������������֮�б�ס��һ����̡�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  __DIR__"southroad",
		"north" :  __DIR__"westroad",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		__DIR__"npc/dianzhu" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -600);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
