//  Room:  /d/lanzhou/yangrouguan.c

inherit  ROOM;

void  create  ()
{
	set("short",  "�����");
	set("long",  @LONG
�������ݳ�����������ݣ�����ȫ�Ǵӳ����ԭ�������ĸ���ɱ
�Ļ����������ۡ����������Ŀ��̣����˵ش�⣬�޲������������
�ʡ����в��ٸ�����Ժ�����ﵽ���͵�ȡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west"  : __DIR__"market",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		__DIR__"npc/xiaoer" : 1,
	]));
	set("coor/x", -9270);
	set("coor/y", 2690);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}