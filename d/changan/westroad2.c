// /d/changan/westroad2.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "�����");
	set  ("long",  @LONG
�������ڳ���������ϣ��Ͼ���Ϊ�೯�Ŷ������ɷǱ�Ѱ��������
�ǹ�¥���ഫ�����������ڴ����ĵ㽫�����Ͽ��Ե��������������ġ�
��ܰ����ݡ�
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"west"  :  __DIR__"westroad1",
		"east"  :  __DIR__"center",
		"north" :  __DIR__"gulou",
		"south" :  __DIR__"zaoxiang",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5050);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
