// /d/changan/zaoxiang.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "����");
	set  ("long",  @LONG
������һ���ľ�����ʯС���У�����������һ�����������Ϸ�����
��������Ҳ�������Ȼȥ����һ�����㡢һ˿���⡢һ��˿����Զ����
¥�ĸ���������Ʈ����
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"north"     :  __DIR__"westroad2",
		"southwest" :  __DIR__"chaguan",
		"southeast" :  __DIR__"dongyuemiao",
		"west"      :  __DIR__"beilin",
		"east"      :  __DIR__"southroad2",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5050);
	set("coor/y", 990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
