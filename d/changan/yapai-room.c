// /d/changan/yapai-room.c.

inherit  ROOM;

void  create  ()
{
	set  ("short",  "Ѻ�Ʒ�");
	set  ("long",  @LONG
�����м����һ�Ű�����������һ������̫ʦ�������ŵľ���ׯ��
�ˡ������������ô����ô���������Ը�֮ǰ�����������ȿ���ǽ�϶�
������(paizi)�ɡ�
LONG);

	set("item_desc",  (["paizi"  :  "

Ѻ�ƹ���
һ��ֻ����һ������ׯ������Ϸ����Ϸ���ƽж�ʮһ�㡣
��������ע������һ�����ӣ�����ʮ���ƽ���ע��������ֱ�Ӱ�Ǯ��ׯ�ҡ�
����Ҫ��һ����(deal)��ֱ�����ƶ�ʮһ�㡣
�ģ���û�б��ƶ�ʮһ��֮ǰ����������(turn)��

ע�����
һ����ͬ����ʱ��ׯ�һ�ʤ������Զ�ʮһ���ʤʱ����˫���⳥��
����A ������Ϊһ����㣬Ҳ������Ϊʮһ����㡣J��Q��K ��ʮ����㡣
�������ĳ�����ҵ�һ����ʧ�Ų�����
�ġ���Ʊ��Ʊ�����ô˴�������ʹ�ã�û�ղ��⡣

		\n"  ]));
	//for  look  something.

	set("exits",  
	([  //sizeof()  ==  4
		"north"  :  __DIR__"clubpoem",
	]));
	
	set("objects",  
	([  //sizeof()  ==  1
		"/d/city/npc/paitong"  :  1,
	]));

	set("no_fight",  1);
	set("no_beg",  1);
	set("no_magic",  1);
	set("no_clean_up",  1);
	set("coor/x", -5030);
	set("coor/y", 1000);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
