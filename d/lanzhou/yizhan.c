// /d/lanzhou/yizhan.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "��վ");
	set  ("long",  @LONG
������������վ�����ڸ������н������ݵ����ʴ��Ͷ�Ҫͨ�����
�����վ����Ⱥ����������һƬæµ�ľ���վǰ����һ��ʯ׮������
һЩ����ʹ󳵣��������������Ĵ��������⡣
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"east"  :  __DIR__"road1",
	]));
	set("no_clean_up",  0);
	setup();
	replace_program(ROOM);
}

