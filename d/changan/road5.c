//  Room:  /d/changan/road5.c

inherit  ROOM;

void  create  ()
{
	set("short",  "��ٵ�");
	set("long",  @LONG
����һ����ʯ�̾͵Ŀ�����ֱ�Ĺٵ�������������·��������ݵ�
��ʮ���ۡ�������ͨ���������������ͨ��С������������ֱ�ﳤ��
�ǡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north"     :  __DIR__"southgate",
		"southeast" :  __DIR__"dayan",
		"southwest" :  __DIR__"xiaoyan",
	]));
	set("outdoors", "guanzhong");
	set("no_clean_up", 0);
	set("coor/x", -5040);
	set("coor/y", 960);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
