//  Room:  /d/luoyang/xiaoxiang.c

inherit  ROOM;

void  create  ()
{
	set("short",  "��ͨ��");
	set("long",  @LONG
���̤�����ӣ����������϶������������ڸ��٣�С����һƬ����
���������������������Ȼ���������硣խխ�����Ӿ�ͷ���ô�һƬ��
��ԣ�ӭ��ҡҷ��������Ȼ���㲻����̾����������ľ�ʿ�û����帣
������
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"      :  __DIR__"tongtuo",
		"north"     :  __DIR__"lvzhulin",
		"southwest" :  __DIR__"xiaojie2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "luoyang");
	set("coor/x", -380);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
