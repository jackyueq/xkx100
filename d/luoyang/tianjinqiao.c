// Room: /d/luoyang/tianjinqiao.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "�������");
	set("long",  @LONG
����������������������󴬶��γɵ�һ�����š�ÿ���賿ʱ�֣�
���»�������գ�������ϵ����˾������������������ˣ��޹ֺ��ƴ�
ʫ����ϣ��д���������غ������⣬��Ӱ��ҡ�̲��������д���续��
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north" :  __DIR__"southgate",
		"south" :  __DIR__"road4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "luoyang");
	set("coor/x", -500);
	set("coor/y", -35);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
