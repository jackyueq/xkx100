// /d/changan/southroad1.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "�ϴ��");
	set  ("long",  @LONG
�������ڳ����ϴ���ϣ��ϴ�����ǳ���ķ����ضΣ�����������
�����ﷷ���ӻ��̡����Ͽ��Կ������ţ��������Ǹ����ֵ��ӻ��̡�
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"north" :  __DIR__"southroad2",
		"south" :  __DIR__"southgate",
		"west"  :  __DIR__"yizhan",
		"east"  :  __DIR__"zahuopu",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5040);
	set("coor/y", 980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
