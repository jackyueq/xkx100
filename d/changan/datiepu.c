// /d/changan/datiepu.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "������");
	set  ("long",  @LONG
����һ�Ҽ�ª�Ĵ����̣����İ���һ����¯��¯��������յ�һƬ
ͨ�죬��һ�߽�ȥ�͸е�������ȡ�ǽ�Ƕ��������깤��δ�깤�Ĳ˵���
������������ذ�ס����׵��һλ������ͷ�󺹻�����������ר����
־���ڴ�����
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"west"  :  __DIR__"southroad2",
	]));
	set("objects",  ([  //sizeof()  ==  4
		__DIR__"npc/tiejiang" : 1,
	]));
	set("coor/x", -5030);
	set("coor/y", 990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
