// /d/changan/xiaoyan.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "С����");
	set  ("long",  @LONG
С�������ھ�����䣬��ȴ�����С���ʳ�С����������ʮ�弶��
˫������Ϊһ���������������ۡ�
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"northeast"  :  __DIR__"road5",
	]));
	set("outdoors",  "changan");
	set("coor/x", -5050);
	set("coor/y", 950);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
