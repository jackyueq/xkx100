inherit NPC;
void create()
{
        set_name("����������", ({ "hasake", "mu min"}));
        set("gender", "����");
        set("age", 26);
        set("long", "һλ��׳�Ĺ��������������ż�ʮֻ��\n");
        set("attitude", "friendly");
        set("combat_exp", 4000 + random(500));
        set("str", 32);
        set("int", 18);
        set("con", 22);
        set("dex", 17);
        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 5);
        set_skill("unarmed", 20);
        set_skill("blade", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);

        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set_temp("apply/damage", 25);
        
        set("inquiry", ([
            "����" : "��������³�˵Ķ��ӣ�������һ���Ǹ��ú��ӣ�\n",
            "��³��" : "��³�������ǹ��������еĴ�Ӣ�ۣ����и����ӽ����ա�\n",
            "����" : "�����ǲ�ԭ��һ�����·�Ļ���\n",
            "������" : "�����˻����������ҵ����ƣ���ҽţ����ƥ�ļ�����\n",
        ]) );

        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
"������������˵�˵: �ϸ��£����õ�������һͷ�ǣ�������Ƥ�͸��۰��á�\n",
"�����������:  ��ӭ�������ǹ����˲��壬��ȥ������������Ұɡ�\n",
        }) );
        carry_object(__DIR__"obj/madao")->wield();
        carry_object(__DIR__"obj/yangao")->wear();
        carry_object(__DIR__"obj/jiunang");
}
