// /d/changan/huachang.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "����");
	set  ("long",  @LONG
��˵����ĵ���������£��������ջ�ȴҲ����ѷɫ����Ƭ�յ�����
���ƽ�ס����Ƴ������������ʮ��ϲ�����ˡ�
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"south"  :  __DIR__"eastroad1",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5020);
	set("coor/y", 1010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
