inherit NPC;
void create()
{
        set_name("����ɮ��",({"seng ren"}));
        set("long", "����һλ��ĸߴ������ɮ�ˣ����۴�׳��������Բ�����ֱֳ�\n"
                    "�У���һϮ�ײ�������ģ��ƺ���һ�����ա�\n");
        set("gender", "����");
        set("attitude", "aggressive");
        set("class", "bonze");

        set("age", 20);
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 1500);
        set("max_jing", 600);
        set("neili", 1000);
        set("max_neili", 1000);
        set("combat_exp", 150000);
        set("score", 100);

        set_skill("force", 50);
        set_skill("hunyuan-yiqi", 50);
        set_skill("dodge", 50);
        set_skill("shaolin-shenfa", 50);
        set_skill("unarmed", 50);
        set_skill("banruo-zhang", 50);
        set_skill("parry", 50);
        set_skill("blade", 50);
        set_skill("cibei-dao", 50);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("unarmed", "banruo-zhang");
        map_skill("parry", "cibei-dao");
        map_skill("blade", "cibei-dao");

        setup();
        carry_object("/d/shaolin/obj/jiedao")->wield();
        carry_object(__DIR__"obj/xuan-cloth")->wear();
}
