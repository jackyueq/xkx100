// /d/changan/dayan.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "������");
	set  ("long",  @LONG
���������꣬ʥɮ����Ϊ������Ҿ��飬���Ƹ����������ɴ�����
�ڡ����ط�ʦ���������м��أ�Ħ�ҹ���һ�£�һ����Ⱥ����ˤ����
�ϣ�ɮ��Ϊ�㼴�������������������������
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"northwest"  :  __DIR__"road5",
	]));
	set("outdoors",  "changan");
	set("coor/x", -5030);
	set("coor/y", 950);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
