//  Room:  /d/changan/zhongnan.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "����ɽ��");
	set  ("long",  @LONG
����ɽ�ֳ�̫��ɽ���೤���ǰ�ʮ������С����������������
֮˵���ݴ���������ɽ�н�����������ٵ���Խ����ɽ�ڣ����������
�ƣ�����ȴû��һ��·������ɽ���������������Ĵ��������ǰ����ԭ��
LONG);
	set("exits",  ([  /*  sizeof()  ==  4  */
    	"east"  :  __DIR__"road2",
    	"west"  :  __DIR__"road3",
	]));
	set("outdoors", "guanzhong");

	set("no_clean_up", 0);
	set("coor/x", -2000);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}




