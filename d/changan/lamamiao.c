// /d/changan/lamamiao.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "������");
	set  ("long",  @LONG
����ԭ�������Ϳ���һ���������ʱ��ס�޵أ��������ɸ�³�ɣ�
�ƽ̣�������������������������˴�Ҷ�����������������
�����·���û������֪�������Ÿ߹ҿ������顰���������Ҷ�һ�顣
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"east"  :  __DIR__"northroad1",
	]));
	set("outdoors",  "changan");
	set("coor/x", -5050);
	set("coor/y", 1020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
