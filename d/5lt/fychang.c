// Room: /d/5lt/fychang.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "��ӳ��");
	set  ("long",  @LONG
�����Ƿ�ӳ������˵�����賿ĳ����Ƭȫ��ͬ����ӳ���컹δ�ڣ�
�����Ѿ�������ռ���Ĵ���
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"west"  :  __DIR__"nroad3",
	]));

	set("no_fight", 1);
	set("coor/x", -140);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
