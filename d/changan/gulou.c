// /d/changan/gulou.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "��¥");
	set  ("long",  @LONG
��¥����������һʮ���ꡣ����ʯΪ������שΪ¥�����غ�ʵ����
¥�ڰ��Ŵ��һ�ţ��ഫ���������ڴ˻��ĵ㽫������������������¥
ǰ�����������׽���ľ��(bian)���ͳ����ĵ���¥ң���Ӧ��
LONG);
	set("item_desc",  ([
		"bian"  : " 
        ********************************************
        *            ����ʢ��    ��������          *
        ********************************************
\n"
	]));
	set("exits",  ([  //sizeof()  ==  4
		"south"  :  __DIR__"westroad2",
	]));
	set("outdoors",  "changan");
	setup();
	replace_program(ROOM);
}

