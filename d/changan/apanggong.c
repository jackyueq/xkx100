// /d/changan/apanggong.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "������");
	set  ("long",  @LONG
������ǰ����������±��ǻ�������ʯ�����￴�ó���ʲô���
��Զ�����ſ�ʯ��(bei)��
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"east" :  __DIR__"road7",
	]));
	set("item_desc",  ([
		"bei" :  "

            ʼ����ʮ���꣬ʹū��ʮ���ڽ���˹�
                 ��������̣���ʦ��¹��
               ������أ�ǧ�﹬�ڸ�֮һ�档

                ���߱���      �����޵�
\n",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	setup();
	replace_program(ROOM);
}

