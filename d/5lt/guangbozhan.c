// Room: /d/5lt/guangbozhan.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "�㲥վ");
	set  ("long",  @LONG
�������ȣ���������������У��е��������ᡣ�����ŷ���������
�㲥վ�����������ֱ��������һ�����磬���в�ʱƮ��������������
�ɣ����˶�Ŀ���¡�
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"west"  :  __DIR__"nroad2",
	]));
	set("no_fight", 1);
	set("coor/x", -140);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
