// Room: /d/5lt/tzoffice.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "̨���칫��");
	set  ("long",  @LONG
�������̨���칫�ң����ڲ�����Ȼ��Ϊ�򵥣�����һ���������
�߾ͱ���������ס�ˡ�
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"west"  :  __DIR__"mishuchu",
	]));
        set("objects", ([
		__DIR__"npc/yoyo": 1,
	]));
	set("no_fight", 1);
	set("coor/x", -175);
	set("coor/y", 30);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
