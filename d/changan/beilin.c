// /d/changan/beilin.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "����");
	set  ("long",  @LONG
����������������ĳ������֡��ഫ���ڱ���Ԫ����䡣�����ﱮ
ʯĹ־�������Ժ����壬���͸��������ֱʡ������׭��������Ŀ����
��������������ʯ�̣�ֱ�������ۻ����ҡ�
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"north"     :  __DIR__"westroad1",
		"east"      :  __DIR__"zaoxiang",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5060);
	set("coor/y", 990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
