// /d/changan/yizhan.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "��վ");
	set  ("long",  @LONG
�����ǳ�����վ�����ڸ������н������������ʴ��Ͷ�Ҫͨ�����
�����վ����Ⱥ����������һƬæµ�ľ���վǰ����һ��ʯ׮������
һЩ����ʹ󳵣��������������Ĵ��������⡣
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"east"  :  __DIR__"southroad1",
	]));
	set("no_clean_up",  0);
	set("coor/x", -5050);
	set("coor/y", 980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
