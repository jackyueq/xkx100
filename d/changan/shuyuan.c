// /d/changan/shuyuan.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "������Ժ");
	set  ("long",  @LONG
������Ժ�Ǹ��µ������ѧ����������������䡣һλׯ�������
��������̫ʦ���Ͻ�ѧ���Ǿ��ǵ������������ˡ�����������������
��ѧ��ѧ����
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"north"  :  __DIR__"eastroad2",
	]));
	set("objects",  ([  //sizeof()  ==  4
		__DIR__"npc/feng" : 1,
	]));
	set("coor/x", -5030);
	set("coor/y", 990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
